#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void){
    int n,i,ans=0;
    double t,a,min=100000;
    cin >> n >> t >> a;
    vector<int> h(n);
    for(i=0;i<n;i++) cin >> h[i];
    for(i=0;i<n;i++){
        double tmp = t-h[i]*0.006;
        if(min>fabs(a-tmp)){
            min = fabs(a-tmp);
            ans=i+1;
        }
    }
    cout << ans;
}