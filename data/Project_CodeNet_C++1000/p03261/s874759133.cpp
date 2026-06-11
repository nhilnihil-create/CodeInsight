#include <iostream>
#include <set>
#include <string>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string pre="";
    set<string> used;
    string w;
    for (int i =0;i<n;i++){
        cin>>w;
        if (i>=1 && pre.back()!=w[0]){
            cout<<"No";
            exit(0);
        }
        pre=w;
        if (used.find(w)!=used.end()){
            cout<<"No";
            exit(0);
        }
        used.insert(w);
    }
    cout<<"Yes";
    
}
