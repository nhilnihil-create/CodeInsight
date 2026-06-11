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

    vector<int> A;

    if(K >=  pow(2,M))
    {
        cout<<-1<<endl;

        return 0;
    }
    if(M == 1 && K == 0) {
        cout<<0<<" "<<0<<" "<<1<<" "<<1<<endl;

        return 0;
    }
    if(M == 1 && K != 0) {
        cout<<-1<<endl;

        return 0;
    }

    for(int i = 0;i < pow(2,M);i++) {
        if(i == K)
            continue;
        A.push_back(i);
    }

    sort(A.begin(),A.end());
    for(int i = 0;i < A.size();i++) {
        cout<<A[i]<<" ";
    }

    cout<<K<<" ";
    sort(A.begin(),A.end(),greater<int>());
    for(int i = 0;i < A.size();i++) {
        cout<<A[i]<<" ";
    }
    cout<<K<<endl;

    return 0;
}
