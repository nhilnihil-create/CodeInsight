#include<bits/stdc++.h>

using namespace std;
int n,a,b;
bool test(int num)
{
    int total=0;
    while (num)
    {
        total = total +num%10;
        num = num/10;
    }
    if(total >=a&&total<=b)
    {
        return true;
    }
    else
    {
        return false;
    }
    


}


int main()
{
    
    cin>>n>>a>>b;
    int answer=0;
    for (size_t i = 1; i <= n; i++)
    {
        if(test(i))
        {
            answer = answer + i;
        }
    }
    cout<<answer<<endl;

}