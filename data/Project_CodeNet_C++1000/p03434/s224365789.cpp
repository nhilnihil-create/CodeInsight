#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    vector<int> vec;
    while(n--){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.rbegin(),vec.rend());
    int alice = 0;
    int bob = 0;
    for(int i=0; i<vec.size(); i++){
        if(i%2==0){
            alice+=vec[i];
        }else{
            bob += vec[i];
        }
    }
    cout << alice - bob <<endl;
}