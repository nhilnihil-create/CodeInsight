#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n,t,a;
    cin >> n >> t >> a;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        vec.push_back(num);
    }
    vector<double> vec2;
    for(int i=0; i<vec.size(); i++){ 
        vec2.push_back(t-(vec[i]*0.006));
    }
    double mn = abs(vec2[0]-a);
    int ind = 0; 
    for(int i=0; i<vec2.size(); i++){
        //cout << vec2[i] <<endl;
        if(abs(vec2[i]-a) < mn){
            mn = abs(vec2[i]-a);
            ind = i;
        }
    }
    cout << ind+1 <<endl;
}