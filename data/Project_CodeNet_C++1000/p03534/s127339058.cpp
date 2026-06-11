#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;
    cin>>s;
    vector<int> v(3,0);
    for(auto a:s){
        switch(a){
            case 'a':
                v[0]++;break;
            case 'b':
                v[1]++;break;
            case 'c':
                v[2]++;break;
        }
    }if(s.length()==2){
        if(v[0]==2||v[1]==2||v[2]==2){
            cout<<"NO";
        }else{
            cout<<"YES";
        }
    }else{
        if(max(v[0],max(v[1],v[2]))-min(v[0],min(v[1],v[2]))>1){
            cout<<"NO";
        }else{
            cout<<"YES";
        }
    }
}
