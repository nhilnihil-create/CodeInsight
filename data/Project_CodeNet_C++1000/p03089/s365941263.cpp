# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int N;
int num;
vector <int> b;
vector <int> ans;
bool possible=true;

int main()
{
    cin>>N;

    for (int i=0; i<N; i++)
    {
        cin>>num;
        b.push_back(num);
    }

    while (possible)
    {
        possible=false;
        
        for (int i=b.size()-1; i>=0; i--)
        {
            if (b[i]==i+1)
            {
                b.erase(b.begin()+i);
                possible=true;
                ans.push_back(i+1);
                break;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    if (b.empty())
    {
        for (int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<endl;
        }
    }

    else
    {
        cout<<"-1"<<endl;
    }
}