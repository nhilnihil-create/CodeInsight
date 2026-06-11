#include<iostream>
#include<queue>
#include<algorithm>
#include<numeric>
#include<string>
#include<map>

using namespace std;
using int_greater_PQ = priority_queue<int,vector<int>,greater<int>>;

int main() 
{
    int N;
    cin>>N;

    multimap<pair<string,int>,int> SP;//first:string second:int
    for (int i = 0; i < N; i++)
    {
        string S;
        int P;
        cin>>S>>P;
        SP.emplace(make_pair(S,(-P)),i+1);
    }

    for(const auto&sp:SP)
    {  
        cout<<sp.second<<endl;
    }
}