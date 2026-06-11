#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n,num;
    cin >> n >> num;
    vector<int> vec;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int count = 0;
    for(int i=0; i<vec.size(); i++){
        num -= vec[i];
        if(num<0){
            break;
        }
        count++;
    }
    if(num>0){
        cout << count-1 <<endl;
    }else{
        cout << count <<endl;
    }
}