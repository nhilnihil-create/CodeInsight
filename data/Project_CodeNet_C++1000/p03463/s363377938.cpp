# include <iostream>
using namespace std;

int main()
{
    int N;
    int A;
    int B;
    cin>>N>>A>>B;
    int diff=B-A;
    if (diff%2==1){
        cout<<"Borys"<<endl;
    }
 
    else
    {
        cout<<"Alice"<<endl;
    }
    return 0;
}