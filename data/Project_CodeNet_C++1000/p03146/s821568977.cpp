#include<bits/stdc++.h>
using namespace std;

int main(){
    int s;
    cin>> s;
    
    set<int> st;
    st.insert(s);

    int cnt = 2;
    while(1){
        if(s%2 == 0){
            //cout<<"偶数"<<endl;
            s = s/2;
            //cout<<s<<endl;
        }else{
            //cout<<"奇数"<<endl;
            s = 3*s + 1;
            //cout<<s<<endl;
        }
        if(st.find(s) != st.end()){
            cout<<cnt<<endl;
            return 0;
        }else{
            st.insert(s);
            cnt++;
        }
        
    }

}