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
    int A,P;
    cin>>A>>P;

    P+=(A*3);

    cout<<P/2<<endl;

    return 0;
}