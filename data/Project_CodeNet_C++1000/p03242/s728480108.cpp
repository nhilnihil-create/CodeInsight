
#include <iostream>
using namespace std;
int main() 
{
    string s;
    cin>>s;
    for(int i=0;i<3;i++){
        cout<<char('1'+'9'-s[i]);
    }
    cout<<endl;
    return 0;
}
