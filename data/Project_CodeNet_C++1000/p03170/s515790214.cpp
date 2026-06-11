    #include <bits/stdc++.h>
    #define BPhuong "vsteps"
    #define maxn 100004
    #define maxm
    #define bit(x, i) ((x>>i)&1)
    #define fid(i,a,b) for(int i = a; i>=b; i--)
    #define fi(i,a,b) for(int i=a;i<=b;i++)
    #define pii pair<int, int>
    #define ll long long
    #define f first
    #define se second
    #define pb push_back
    using namespace std;
    int n, a[maxn], k, b[maxn];
    void nhap(){
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);cout.tie(NULL);
        srand(time(NULL));
        cin >> n >> k;
        fi(i, 1, n) cin >> a[i];
    }
    void xuli(){
        fi(i, 0, k){
            fi(j, 1, n){
                if(b[i] == 0 && a[j]+i <= k){
                    b[i+a[j]] = 1;
                }
            }
        }
        if(b[k]) cout << "First" << '\n';
        else cout << "Second" << '\n';
    }
    int main(){
        nhap();
        xuli();
    }
