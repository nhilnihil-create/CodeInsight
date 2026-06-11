# include <iostream>
using namespace std;

string S;
long long counter=0;
int w=1;

int main()
{
    cin>>S;

    for (int i=0; i<S.size(); i++)
    {
        if (S[i]=='W')
        {
            counter=counter+i-(w-1);
            w++;
        }
    }

    cout<<counter<<endl;
}