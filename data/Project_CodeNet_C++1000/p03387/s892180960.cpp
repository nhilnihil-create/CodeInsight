#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define INF 10101010

int main()
{
    vector<int> num(3);
    cin >> num[0] >> num[1] >> num[2];
    int count=0;
    ssort(num);
    while(num[1]<num[2]){
        num[0]++;num[1]++;count++;
    }
    if((num[2]-num[0])%2==1){
        num[2]++;num[1]++;count++;
    }
    while(num[0]<num[2]){
        num[0]+=2;count++;
    }

    cout << count << endl;

}