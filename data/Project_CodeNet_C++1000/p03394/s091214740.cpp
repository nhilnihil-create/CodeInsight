#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

int main()
{
    int N;
    cin >> N;

    if (N == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }

    int MAX = 30000;

    vector<int> ans;
    ans.push_back(2);
    ans.push_back(3);
    ans.push_back(4);
    ans.push_back(9);

    int x6 = 6;
    int x2 = 8;
    int x3 = 15;

    for(int i = 4; i < N; i++) {
        if(i < N - 1 && x2 + 2 <= MAX) {
            ans.push_back(x2);
            ans.push_back(x2 + 2);
            x2 += 6;
            i++;
        }else if(i < N - 1 && x3 + 6 <= MAX) {
            ans.push_back(x3);
            ans.push_back(x3 + 6);
            x3 += 12;
            i++;
        }else{
            ans.push_back(x6);
            x6 += 6;
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans.size() > N && ans[i] == MAX)
            continue;
        if (i == 0)
            cout << ans[i];
        else
            cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}