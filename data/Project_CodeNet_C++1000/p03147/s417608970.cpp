#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> h[i];
    }
    
    int tmp = *std::max_element(h.begin(), h.end());
    std::vector<int> flag(0);
    for (int i = 0; i < tmp; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (h[j] > 0)
            {
                flag.push_back(1);
            }
            else
            {
                flag.push_back(0);
            }
            h[j]--;
        }
        flag.push_back(0);
    }
    
    int count = 0;
    for (int i = 0; i < (int)flag.size() - 1; i++)
    {
        if (flag[i] == 1 && flag[i + 1] == 0)
        {
            count++;
        }
    }
    
    std::cout << count << std::endl;

    return 0;
}