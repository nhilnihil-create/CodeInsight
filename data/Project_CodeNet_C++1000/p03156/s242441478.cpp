#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    int e=0,f=0,g=0;
    for(int i=0;i<n;i++){
        if(p[i] <= a){
            e++;
        }else if(p[i] <= b){
            f++;
        }else{
            g++;
        }
    }
    int ans = min(min(e,f),g);
    cout << ans << endl;
    return 0;
}