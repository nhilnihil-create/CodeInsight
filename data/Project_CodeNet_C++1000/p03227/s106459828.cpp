#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    if(s.size()==2){
        cout<<s<<endl;
    }else{
        swap(s.at(0), s.at(2));
        cout<<s<<endl;
    }
    return 0;
}