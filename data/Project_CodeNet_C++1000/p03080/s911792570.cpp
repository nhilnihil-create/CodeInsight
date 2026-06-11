#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define LOVE ios::sync_with_stdio(0)
#define Foru(i,a,b) for(int i=(a);i<=(b);++i)
#define File ifstream fin("G:\\QtCode\\data\\in.txt")
using namespace std;
//void slove(int question_num)
//{
//    while(question_num--)
//    {
//        int sum[200002]={0};
//        int n;
//        cin>>n;
//        set<int>ans;
//        int num[200002]={0};
//        for(int i=1;i<=n;i++)
//        {
//            cin>>num[i];
//            sum[i]+=sum[i-1]+num[i];
//        }
//        for(int i=2;i<n;i++)
//        {
//            set<int>temp;
//            for(int j=i;j<=n;j++)
//            {
//                temp.insert(sum[j]-sum[j-i]);
//            }
//            if(temp.count((1+i)*i/2))
//                ans.insert(i);
//        }
//        cout<<1;
//        for(int i=2;i<n;i++)
//        {
//            if(ans.count(i))
//                cout<<1;
//            else cout<<0;
//        }
//        cout<<1<<endl;

//    }
//    return;
//}
//void slove(int question_num)
//{
//    while(question_num--)
//    {
//        unsigned int n;cin>>n;
//        map<int,int,greater<int> >temp;
//        for(unsigned int i=1;i<=n;i++)
//        {
//            int kkk;cin>>kkk;
//            temp[kkk]++;
//        }
//        if(temp.size()==1)
//            cout<<0<<' '<<0<<' '<<0<<endl;
//        else
//        {
//            int medalnum=n/2;
//            int tot=0;
//            int ans[5]={0};
//            auto pos=temp.begin();
//            ans[1]=temp.begin()->second;
//            int flage=1;
//            for(;pos!=temp.end();pos++)
//            {
//                tot+=pos->second;
//                if(tot>medalnum)
//                {
//                    tot-=pos->second;
//                    break;
//                }
//            }
//            for(auto it=++temp.begin();it!=pos;it++)
//            {
//                if(ans[2]<=ans[1])
//                    ans[2]+=it->second;
//                else flage=0;
//                if(!flage)
//                {
//                    ans[3]+=it->second;
//                }
//            }
//            if(ans[3]<=ans[1])
//                cout<<0<<' '<<0<<' '<<0<<endl;
//            else
//                cout<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<endl;
//        }
//    }
//    return;
//}
void slove(int question_num)
{
    while (question_num--) {
        int n;cin>>n;
        int r=0,b=0;
        for(int i=1;i<=n;i++)
        {
            char x;cin>>x;
            if(x=='R')
                r++;
            else b++;
        }
        if(r>b) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
int main()
{
    LOVE;
    //int n;cin>>n;
    slove(1);
    return 0;
}
