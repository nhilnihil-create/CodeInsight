#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    int j=0;
    for(int i=0;i<n;i++){
        cin >> s;
        if(s=="Y"){
            j=1;
        }
    }
    if(j==0)
        cout << "Three"<< endl;
    if(j==1)
        cout << "Four" << endl;
}