#include <bits/stdc++.h>
using namespace std;

vector<int>two,three,six,ans;

int main()
{
    int n;
    cin>>n;
    if(n==3)
    {
        cout<<"2 5 63"<<endl;
        return 0;
    }
    if(n==4)
    {
        cout<<"2 5 20 63"<<endl;
        return 0;
    }
    for(int i=2;i<=30000;i++)
    {
        if(i%6==0)
        {
            six.push_back(i);
            continue;
        }
        if(i%2==0)two.push_back(i);
        if(i%3==0)three.push_back(i);
    }

    ans.push_back(three.back());
    three.pop_back();
    ans.push_back(three.back());
    three.pop_back();
    n-=2;
    while(n>=2 && two.size()>=2)
    {
        ans.push_back(two.back());
        two.pop_back();
        ans.push_back(two.back());
        two.pop_back();

        n-=2;
    }
    while(n>=2 && three.size()>=2)
    {
        ans.push_back(three.back());
        three.pop_back();
        ans.push_back(three.back());
        three.pop_back();
        n-=2;
    }

    for(int i=0;i<n;i++)ans.push_back(six[i]);
    bool flag=0;
    for(int i=0;i<ans.size();i++)
    {
        if(flag)printf(" ");
        flag=1;
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
