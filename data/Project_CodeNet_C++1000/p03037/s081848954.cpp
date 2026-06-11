#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin, (x).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
// scanf("%d %d %d %d",&w,&b,&d,&s); %lld
// printf("%d\n" ,points);
// const double PI=acos(-1);

const int MAX=1e5+5;
int prefix[MAX];

int main(){
    int n,m,l,r,rta=0,aux=0;
    vector<pii> in;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> l >> r;
        prefix[l-1]++;
        prefix[r]--;
    }
    for(int i=1;i<=n;i++){
        prefix[i]+=prefix[i-1];
    }
    for(int i=0;i<n;i++){
        if(prefix[i]==m) rta++;
    }
    cout << rta << endl;
    return 0;
}
