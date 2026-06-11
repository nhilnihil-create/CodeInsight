# include <iostream>
using namespace std;

int N;
int A, B, C, D;
string S;
int consecutiverocks=0;
int consecutiveblanks=0;

int main()
{
    cin>>N>>A>>B>>C>>D;
    cin>>S;

    for (int i=A-1; i<=C-1; i++)
    {
        if (S[i]!='#')
        {
            consecutiverocks=0;
        }

        else if (S[i]=='#')
        {
            consecutiverocks++;
        }

        if (consecutiverocks==2)
        {
            cout<<"No"<<endl;
            return 0;
        }
    }  

    for (int i=B-1; i<=D-1; i++)
    {
        if (S[i]!='#')
        {
            consecutiverocks=0;
        }

        else if (S[i]=='#')
        {
            consecutiverocks++;
        }

        if (consecutiverocks==2)
        {
            cout<<"No"<<endl;
            return 0;
        }
    } 

    if (A<B && B<C && C<D)
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    else if (A<C && C<B && B<D)
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    else if (A<B && B<D && D<C)
    {
        for (int i=B-2; i<=D; i++)
        {
            if (S[i]=='.')
            {
                consecutiveblanks++;
            }

            else if (S[i]=='#')
            {
                consecutiveblanks=0;
            }

            if (consecutiveblanks==3)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;
}