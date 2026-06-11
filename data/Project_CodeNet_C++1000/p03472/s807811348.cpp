# include <iostream>
# include <deque>
# include <math.h>
# include <algorithm>
using namespace std;

int N;
int H;
int a[100005];
int b[100005];
deque< pair<int, char> > katanas;
long long counter=0;
long long throws=0;

bool sortkatanas(pair <int, char> a, pair <int, char> b)
{
    if (a.first>b.first)
    {
        return true;
    }

    return false;
}

int main()
{
    cin>>N>>H;

    for (int i=1; i<=N; i++)
    {
        cin>>a[i]>>b[i];
    }

    for (int i=1; i<=N; i++)
    {
        katanas.push_back(make_pair(a[i], 'a'));
        katanas.push_back(make_pair(b[i], 'b'));
    }

    sort(katanas.begin(), katanas.end(), sortkatanas);

    for (int i=0; i<katanas.size(); i++)
    {
        if (katanas[i].second=='b')
        {
            counter=counter+katanas[i].first;
            throws=throws+1;
            if (counter>=H)
            {
                break;
            }
        }

        if (katanas[i].second=='a')
        {
            throws=throws+ceil((double)(H-counter)/katanas[i].first);
            break;
        }
    }

    cout<<throws<<endl;
}