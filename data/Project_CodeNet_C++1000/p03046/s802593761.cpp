#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<climits>
#include<fstream>

#define MOD (1000000007)

using namespace std;

typedef long long int Int;

constexpr Int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n-1); }

int M,K;

int main(void) {
    cin>>M>>K;

    if (K >= pow(2.0,M)) {
        cout<<-1<<endl;

        return 0;
    }
    
    if(M == 1) {
        if(K == 1) {
            cout<<-1<<endl;

            return 0;
        } else if(K == 0) {
            cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl;

            return 0;
        }
    }

    vector<int> up;
    for(int i = 0;i < pow(2.0,M);i++) {
        if(i != K)
            up.push_back(i);
    }

    vector<int> a;
    sort(up.begin(),up.end());
    for(int i = 0;i < up.size();i++)
        a.push_back(up[i]);
    a.push_back(K);
    sort(up.begin(),up.end(),greater<int>());
    for(int i = 0;i < up.size();i++)
        a.push_back(up[i]);
    a.push_back(K);

    for(int i = 0;i < a.size();i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}


