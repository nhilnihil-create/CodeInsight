#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200105
int word[200105];
const int len = 200005;
 
int main() {
    int n; cin >> n;

    int a[n] = {};
    rep(i,n)cin >> a[i];

    int sakujo = 0;
    int f[n] = {};
    srep(i,1,n-1){
        if(a[i-1]<a[i] && a[i]<a[i+1] && 200 < a[i-1]){
            f[i] = 1;
            sakujo++;
        }else if(a[i+1] < a[i] && a[i] < a[i-1] && 200 < a[i+1]){
            f[i] = 1;
            sakujo++;
        }
    }

    int ccc = 0;
    rep(i,n){
        if(f[i]==0){
            a[ccc] = a[i];
            ccc++;
        }
    }
    n = n - sakujo;

    srep(i,1,n-1){
        if(a[i-1]>a[i] && a[i]<a[i+1] && a[i]>250){
            a[i] = 250;
        }
    }

    srep(i,1,n-1){
        if(a[i-1]<a[i] && a[i]<a[i+1] && a[i-1] <= 260 && 270 <= a[i+1]){
            a[i] = 265;
        }
    }

    srep(i,1,n-1){
        if(a[i-1]>a[i] && a[i]>a[i+1] && a[i+1] <= 260 && 270 <= a[i-1]){
            a[i] = 265;
        }
    }

    srep(i,1,n-1){
        if(a[i-1]<a[i] && a[i]>a[i+1] && 270 <= a[i]){
            a[i] = 270;
        }
    }
    

    // 1種類でいけるかの判定
    if(n == 1){
        cout << '1' << endl;
        return 0;
    }
    srep(i, 1, n){
        if(a[i] <= a[i-1]){
            break;
        }
        if(i == n-1){
            cout << '1' << endl;
            return 0;
        }
    }

    // 文字の種類数
    int count = 2;

    int l = 2;
    int r = n;

    while(true){
        int count = (l+r)/2;
        int burst = 0; //フラグ
        rep(i,len)word[i] = 0;
        rep(i, n){
            if(i == 0){ // 初期条件（例：a[0]=5の時、あああああ）
                rep(j, min(a[0],len)){
                    word[j] = 1;
                }
                continue;
            }else if(a[i] > a[i-1]){
                if(a[i-1]<len){
                    srep(j,a[i-1],min(a[i],len)){
                        word[j] = 1;
                    }
                }
                continue;
            }

            drep(j,min(a[i],len)){
                if(j==(min(a[i],len) - 1)){
                    word[j]++;
                }
                if(word[j]==count + 1){
                    if(j==0){
                        burst = 1;
                        break;
                    }
                    word[j] = 1;
                    word[j-1]++;
                }
            }
            if(burst==1)break;
            srep(j,a[i],min(a[i-1],len)){
                word[j] = 0;
            }
        }
        if(burst == 1){
            l = count + 1;
        }else{
            r = count;
        }
        if(l==r)break;
    }

    cout << r << endl;
    return 0;
}
 
