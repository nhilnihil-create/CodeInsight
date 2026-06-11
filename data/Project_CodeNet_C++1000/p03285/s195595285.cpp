#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin>>N;
    string s;
    s = "No";
    for(int i=0;i<26;i++){
        for(int j=0;j<15;j++){
            int n = 4*i+7*j;
            if(n==N){
                s = "Yes";
            }
        }
    }
    cout<<s<<endl;
}