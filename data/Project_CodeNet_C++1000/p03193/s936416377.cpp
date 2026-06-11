#include <iostream>
#include <vector>
#include <functional>
#include <iomanip>
int MOD=1e9+7;
using namespace std;
int main(){
    int n,h,w;
    cin >> n >> h >> w;
    int c=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        if(a>=h && b>=w){
            c++;
        }
    }
    cout<<c<<endl;
}
