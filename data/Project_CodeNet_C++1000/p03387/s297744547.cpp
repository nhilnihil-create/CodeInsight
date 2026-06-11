#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> a(3);
    std::cin >> a[0] >> a[1] >> a[2];

    int max = std::max({a[0], a[1], a[2]});

    int cnt = 0;
    while (a[0] < max)
    {
        a[0] += 2;
        cnt++;
    }

    while (a[1] < max)
    {
        a[1] += 2;
        cnt++;
    }

    while (a[2] < max)
    {
        a[2] += 2;
        cnt++;
    }

    int cnta = 0;
    for (int i = 0; i < 3; i++)
    {
        if(max < a[i]) {
            cnta++;
        }
    }

    if(a[0]== a[1] && a[1]==a[2]) {
        std::cout << cnt << "\n";
    } 
    if(cnta == 2) {
        std::cout << cnt - 1 << std::endl;
    } 
    
    if(cnta == 1){
        std::cout << cnt + 1 << std::endl;
    }
}