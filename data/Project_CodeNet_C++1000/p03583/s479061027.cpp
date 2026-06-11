#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define rep(i,j,k) for(i=j;i<(k);i++)
#define rrep(i,j,k) for(i=j;i>(k);i--)
typedef long long int lli;

using namespace std;

int main() {
    lli N,n,h;
    double w;
    lli i,j;
    cin>>N;
    rep(h,1,3501){
        rep(n,h,3501){
            if(4*h*n-N*n-N*h>0){
                w=(double)N*(double)h*(double)n/(4.0*(double)h*(double)n-(double)N*(double)n-(double)N*(double)h);
                if(floor(w)==w&&w>0&&w<3501){
                    cout<<h<<" "<<n<<" "<<(int)w<<" "<<endl;
                    exit(0);
                }
            }
        }
    }
}
