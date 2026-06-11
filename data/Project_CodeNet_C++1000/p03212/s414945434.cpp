#include <iostream>
#include <vector>
using namespace std;

int count753(vector<int> &usenum, int n, int cur){
    int ans = 0;

    if(cur <= n){
        if(usenum[3] >= 1 && usenum[5] >= 1 && usenum[7] >= 1){
            ans++;
        }
    }

    int cketa = 0;
    {
        int cur1 = cur;
        while(cur1 > 0){
            cur1 /= 10;
            cketa++;
        }
    }

    int nketa = 0;
    {
        int n1 = n;
        while(n1 > 0){
            n1 /= 10;
            nketa++;
        }
    }

    switch(nketa-cketa){
        case 1:
        if(cur*10+3 <= n && usenum[5] >= 1 && usenum[7] >= 1){
            ans++;
        }

        if(cur*10+5 <= n && usenum[3] >= 1 && usenum[7] >= 1){
            ans++;
        }

        if(cur*10+7 <= n && usenum[5] >= 1 && usenum[3] >= 1){
            ans++;
        }
        break;

        case 2:
        if(usenum[5] >= 1 || usenum[7] >= 1){
            usenum[3]++;
            ans += count753(usenum, n, cur*10+3);
            usenum[3]--;
        }

        if(usenum[3] >= 1 || usenum[7] >= 1){
            usenum[5]++;
            ans += count753(usenum, n, cur*10+5);
            usenum[5]--;
        }

        if(usenum[5] >= 1 || usenum[3] >= 1){
            usenum[7]++;
            ans += count753(usenum, n, cur*10+7);
            usenum[7]--;
        }
        break;

        default:
        usenum[3]++;
        ans += count753(usenum, n, cur*10+3);
        usenum[3]--;
        usenum[5]++;
        ans += count753(usenum, n, cur*10+5);
        usenum[5]--;
        usenum[7]++;
        ans += count753(usenum, n, cur*10+7);
        usenum[7]--;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> usenum(10, 0);
    cout << count753(usenum, n, 0) << endl;
    return 0;
}