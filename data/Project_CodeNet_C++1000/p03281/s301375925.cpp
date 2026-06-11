#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int enum_divisors(int N)
{
    vector<int> res;
    for (int i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    return res.size();
}

int main(){
    bool ans[200];
    rep(i,200){
        if(i%2==0){
            if(enum_divisors(i+1)==8)
                ans[i] = true;
            else
                ans[i] = false;
        }else{
            ans[i] = false;
        }
    }

    int n;  cin >> n;
    int a(0);
    for(int i=0;i<n;i++)
        if(ans[i])  a++;

    cout << a << endl;

    return 0;
}