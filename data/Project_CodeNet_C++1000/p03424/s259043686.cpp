#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<char>st;
    for(int i=0;i<n;i++)
    {
        char element;
        cin>>element;
        st.insert(element);
    }
    if(st.size()==3){
        cout<<"Three\n";
    }
    else
    {
        cout<<"Four\n";
    }
}