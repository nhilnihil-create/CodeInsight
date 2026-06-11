#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n,m,x;
    cin >> n >> m >>x;
    vector<int> vec;
    int left =0;
    int right =0;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        vec.push_back(a);
        if(a<x){
            left++;
        }else{
            right++;
        }
    }
    if(right>left){
        cout << left <<endl;
    }else{
        cout << right <<endl;
    }
    
}