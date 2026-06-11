#include <bits/stdc++.h>
using namespace std;
     
int main() {
    string s;
    string t;
    cin>>s>>t;
    // cout << s<<t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    int s_length =(int)(s.length());
    int t_length =(int)(t.length());
    string td=t;
       

    for(int i=0;i<t_length;i++){
        td.at(i)=t.at(t_length-i-1);
    }
    
    if(s<td){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}