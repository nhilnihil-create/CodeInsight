#include <iostream>
using namespace std;
int main()
{
    string a;
    cin>>a;
    if(a=="abc")
        cout<<"Yes";
        else if(a=="acb")
            cout<<"Yes";
            else if(a=="bac")
               cout<<"Yes";
               else if(a=="bca")
                  cout<<"Yes";
                  else if(a=="cab")
                     cout<<"Yes";
                     else if(a=="cba")
                        cout<<"Yes";
                        else
                            cout<<"No";


	return 0;
}
