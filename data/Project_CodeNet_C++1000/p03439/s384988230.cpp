#include<iostream>
#include<string>
using namespace std;

int main() {
    int N;
    cin>>N;
    string resultl, resultr, resultmiddle;;
    int l=0, r=N;
    int middle;
    cout<<l<<endl<<flush;
    cin>>resultl;
    while((resultl != "Vacant") & (resultr != "Vacant")){
        middle = (l+r)/2;
        cout<<middle<<endl<<flush;
        cin>>resultmiddle;
        if(((middle - l) % 2 == 0) & (resultl == resultmiddle)){
            l = middle;
            resultl = resultmiddle;
        }
        else if(((middle - l) % 2 != 0) & (resultl != resultmiddle)){
            l = middle;
            resultl = resultmiddle;
        }
        else {
            r = middle;
            resultr = resultmiddle;
        }
    }
    /**
    if(resultl == "Vacant") cout<<l<<endl;
    else cout<<r<<endl;
    **/
}
