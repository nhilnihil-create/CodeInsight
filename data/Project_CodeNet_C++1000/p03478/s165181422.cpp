#include <iostream>
#include <string>
using namespace std;
int n;
int a,b;

int main() {
    cin>>n>>a>>b;
    int answer=0;
    for(int i=0;i<=n;i++)
    {
        string temp= to_string(i);
        int count=0;
        for(int t=0;t<temp.length();t++)
        {
            count+=temp[t]-'0';
        }
        if(count>=a&&count<=b)
        answer+=i;
    }
    cout<<answer;
}
