#include <iostream>
#define print(x) cout<<x<<endl;
using namespace std;


int main() {
    string n;
    cin>>n;
    int lossCount=0;
    for(unsigned int i=0; i<n.size();i++)
    {
        if(n.at(i)=='x'){
            lossCount++;
        }
            
    }
    if(lossCount>7){
        print("NO");
    }else{
        print("YES");
    }
    return 0;
}
