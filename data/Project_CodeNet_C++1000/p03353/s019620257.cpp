# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
using namespace std;

string s;
int K;
map<string, bool> visited;
vector<string> vstring;

int main()
{
    cin>>s;
    cin>>K;

    for (int i=0; i<s.size(); i++)
    {
        for (int j=1; j<=min((int)s.size()-i, K); j++)
        {
            if (!visited[s.substr(i,j)])
            {
                vstring.push_back(s.substr(i,j));
                visited[s.substr(i,j)]=true;
            }
        }
    }

    sort(vstring.begin(), vstring.end());

    cout<<vstring[K-1]<<endl;
}