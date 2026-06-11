#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;
typedef long long int ll;
typedef vector<ll> vll;

#define IO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define forn(s, e) for(int i=s; i<e; ++i)
#define MOD 1000000007
#define F first
#define S second
#define all(v) v.begin(), v.end()

int main(){
    IO
    int n, a, b;
    cin >> n >> a >> b;

    vi q(n);
    forn(0, n)
        cin >> q[i];
    
    sort(all(q));
    int i=0, count = 0;
    vi done;
    done.assign(n, 0);
    bool f;
    for(int i=0; i<n; ++i){
        f = true;
        if(!done[i] && q[i] <= a){
            for(int j=i+1; j<n && f; ++j){
                if(!done[j] && q[j]>a && q[j]<=b){
                    for(int k=j+1; k<n && f; ++k){
                        if(!done[k] && q[k]>b){
                            done[i] = done[j] = done[k] = 1;
                            //cout << ">" << i << " "  << j << " " << k << endl;
                            ++count;
                            f= false;
                            break;
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}