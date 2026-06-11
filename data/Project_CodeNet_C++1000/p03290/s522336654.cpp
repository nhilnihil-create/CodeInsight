#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d,g;
    cin>>d>>g;
    vector<int> p(d),c(d);
    for(int i=0;i<d;i++)
    {
        cin>>p.at(i)>>c.at(i);
    }
    int count = 10000;
    for(int tmp=0;tmp<(1 << 10);tmp++)
    {
        int tmp_count = 0;
        int tmp_score = 0;
        bitset<10> b(tmp);
        for(int i=0;i<d;i++)
        {
            if(b.test(i))
            {
                tmp_count += p.at(i);
                tmp_score += p.at(i)*100*(i+1) + c.at(i);
            }
        }
        int num = d-1;
        while(tmp_score < g)
        {
            if(!b.test(num))
            {
                for(int j = 0;j < p.at(num);j++)
                {
                    tmp_score += 100*(num + 1);
                    tmp_count++;
                    if(tmp_score >= g)
                    {
                        break;
                    }
                }
                if(tmp_score < g)
                {
                    tmp_score += c.at(num);
                }
            }
            num--;
        }
        if(tmp_count < count)
        {
            count = tmp_count;
        }
    }
    cout<<count<<endl;
}