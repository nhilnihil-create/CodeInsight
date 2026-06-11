#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    if(s=="AKIHABARA")cout<<"YES"<<endl;
    else if(s=="KIHARABA")cout<<"YES"<<endl;
    else if(s=="AKIHBARA")cout<<"YES"<<endl;
    else if(s=="AKIHABRA")cout<<"YES"<<endl;
    else if(s=="AKIHABAR")cout<<"YES"<<endl;
    else if(s=="KIHBARA")cout<<"YES"<<endl;
    else if(s=="KIHABRA")cout<<"YES"<<endl;
    else if(s=="KIHABAR")cout<<"YES"<<endl;
    else if(s=="AKIHBRA")cout<<"YES"<<endl;
    else if(s=="AKIHBAR")cout<<"YES"<<endl;
    else if(s=="AKIHABR")cout<<"YES"<<endl;
    else if(s=="KIHBRA")cout<<"YES"<<endl;
    else if(s=="KIHBAR")cout<<"YES"<<endl;
    else if(s=="KIHABR")cout<<"YES"<<endl;
    else if(s=="AKIHBR")cout<<"YES"<<endl;
    else if(s=="KIHBR")cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}