# include <iostream> 
# include <algorithm>
using namespace std; 

int N;
int x;
int a[105];
long long sum=0;
int happy=0;

int main()
{
    cin>>N>>x;

    for (int i=1; i<=N; i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }

    sort(a+1, a+N+1);

    if (x==sum)
    {
        cout<<N<<endl;
    }

    else if (x>sum)
    {
        cout<<N-1<<endl;
    }

    else if (x<sum)
    {
        for (int i=1; i<=N; i++)
        {
            x=x-a[i];
            
            if (x<0)
            {
                cout<<happy<<endl;
                break;
            }

            else if (x==0)
            {
                happy=happy+1;
                cout<<happy<<endl;
                return 0;
            }

            else
            {
                happy=happy+1;
            }
        }
    }
}