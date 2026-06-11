#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,int> P;
const LL mod=1000000007;
const LL LINF=1LL<<62;
const LL INF=1<<17;

int main(){
    int N;cin >> N;
    LL s=0;
    if(N==1){
        s=2;
    }
    for(LL i=1;i<=N;i++){
        if(i*(i-1)==2*N){
            s=i;
            break;
        }
    }
    if(s==0){
        puts("No");
        return 0;
    }
    int ans[s][s-1];
    int a=1;
    for (int i = 0; i < s-1; i++) {
        for(int j=i;j<s-1;j++){
            ans[i][j]=a;
            ans[j+1][i]=a++;
        }
    }
    puts("Yes");
    cout << s << endl;
    for (int i = 0; i < s; i++) {
        cout << s-1 << " ";
        for (int j = 0; j < s-1; j++) {
            cout << ans[i][j] << (j==s-2?"\n":" ");
        }
    }
    return 0;
}
