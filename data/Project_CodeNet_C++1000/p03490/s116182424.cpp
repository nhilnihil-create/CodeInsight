#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 8e3 + 3;

vector< int > V[2];
int H[N+N],HH[N+N],n,X,Y,i,h,hh,ss;
char A[N];

void f(vector <int> &r){
    int i,j,x;
    for(i=0;i<r.size();i++){
        x = r[i];
        for(j=n; j>=-n+x; j--){
            if(H[j-x+N] == 1) HH[j+N] = 1;
        }
        for(j=-n;j<=n-x;j++){
            if(H[j+x+N] == 1) HH[j+N] = 1;
        }
        for(j=-n;j<=n;j++) { H[j+N] = HH[j+N]; HH[j+N] = 0; }
    }
}

int main(){
    cin >> A+1 >> X >> Y;
    n = strlen(A+1);
    for(i=1;i<=n;i++){
        if(A[i] == 'T'){
            if(h || hh) V[h].pb(ss);
            else H[ss+N] = 1;
            hh = 1;
            h = 1-h;
            ss = 0;
        }
        else ss++;
    }
    if(h || hh) V[h].pb(ss);
    else H[ss+N] = 1;
            
    f(V[0]);    
    if(H[X+N] == 0){ puts("No"); return 0; }
    memset(H , 0 , sizeof H);
    H[N] = 1;
    f(V[1]);
    puts(H[Y+N] ? "Yes" : "No");
    return 0;
}
