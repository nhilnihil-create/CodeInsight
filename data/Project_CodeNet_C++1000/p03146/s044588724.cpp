#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int curr=1;
    set<int> s;
    s.insert(n);
    while( true)
    {
        if(n%2==0)
        {
            curr++;
            n=n/2;
          //  cout<<"n is "<<n <<" and curr is "<<curr<<"\n";
            if( s.find(n)== s.end() )
            {
                s.insert(n);
            }
            else {
                cout << curr;
                break;
            }

        } else
        {
            n= 3*n+1;
            curr++;
            //cout<<"n is "<<n <<" and curr is "<<curr<<"\n";
            if( s.find(n)== s.end())
            {
                s.insert(n);
            }
            else {
                cout << curr;
                break;
            }
        }
    }
}