#include <iostream>
#include <deque>
using namespace std;
int main()
{
    string s , t;
    cin >>s >> t;
    int n = s.size();
    for (int i = 0 ; i< n;i++){
        if (s==t){
            cout<<"Yes"<<endl;
            return 0 ;
        }
        s = s.back()+s;
        s.pop_back();
    }
    
    cout<<"No"<<endl;
    return 0;
}
