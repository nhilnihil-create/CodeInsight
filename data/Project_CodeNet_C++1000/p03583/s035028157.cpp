#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<cctype>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll h,n,w;
    for(h=1;h<3500;h++){
        for(n=1;n<3500;n++){
            if((4*h*n-n*N-N*h)!=0)w=N*h*n/(4*h*n-n*N-N*h);
            if(w>0&&4*h*n*w==N*(h*n+n*w+w*h)){
                cout << h <<" " <<n << " "<<w <<endl;
                return 0;
            }
        }
    }
    return 0;
}
