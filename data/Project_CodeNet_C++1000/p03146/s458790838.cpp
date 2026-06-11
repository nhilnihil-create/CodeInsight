#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    int num = n;
    set<int> st;
    for(int i=1; i<1000000; i++){
        st.insert(num);
        if(num%2==0){
            num/=2;
        }else{
            num = (num*3) +1;
        }
        if(st.count(num) > 0){
            cout << i+1 <<endl;
            break;
        }
    }
}