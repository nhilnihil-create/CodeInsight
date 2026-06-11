#include<bits/stdc++.h>
#define taskname "A"
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int maxn = 5e5 + 5;
multiset<int,greater<int>> s[maxn];
int n , a[maxn];

int main(){
    if(fopen(taskname".INP","r")){
        freopen(taskname".INP","r",stdin);
        freopen(taskname".OUT","w",stdout);
    }
    int n , A , B;cin >> n >> A >> B;
    if(A + B > n + 1 || (ll)A * B < n)return cout << -1 , 0;
    int rem = n - A;
    int now = 0;
    for(int i = 1 ; i <= A ; ++i){
        for(int j = now + min(rem , B - 1) + 1 ; j >= now + 1 ; --j){
            cout << j << " ";
        }
        now += min(rem , B - 1) + 1;
        rem -= min(rem , B - 1);
    }
}

