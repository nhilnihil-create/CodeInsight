#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;
int N,Q;
vector<pair<char,char > > v;
vector <char> t,d;
vector <char> Sir;
string s;
//bool Golems[20010];
map <char,int> Letters;
int cntGolems;
int verificare(int mijloc,int directie)
{
    int i;
    for(i=0;i<=Q-1;i++)
    {
        if(s[mijloc]==t[i])
        {
            if(d[i]=='R')
            {
                mijloc++;
            }
            else
            {
                mijloc--;
            }
        }
        if(directie==1)
        {
            if(mijloc>=N)
            {
                return false;
            }
            if(mijloc<0)
            {
                return true;
            }
        }
        else//directie==2
        {
            if(mijloc<0)
            {
                return false;
            }
            if(mijloc>=N)
            {
                return true;
            }
        }

    }
    return false;
}
int cautare(int st,int dr,int directie)//1 pentru STANGA, 2 pentru DREAPTA
{
    int mijloc,sol_st,sol_dr;
    sol_st=-1;
    sol_dr=N;
    while(st<=dr)
    {
        mijloc=st+(dr-st)/2;
        if(directie==1)//directie==1
        {
            if(verificare(mijloc,directie)==true)
            {
                sol_st=mijloc;
                st=mijloc+1;
            }
            else
            {
                dr=mijloc-1;
            }
        }
        else//directie==2
        {
            if(verificare(mijloc,directie)==true)
            {
                sol_dr=mijloc;
                dr=mijloc-1;
            }
            else
            {
                st=mijloc+1;
            }
        }
    }
    if(directie==2)
        return sol_dr;
    else//directie==1
        return sol_st;
}
int main()
{
    cin>>N>>Q;
    //Sir.push_back('#')
    cin>>s;
    //cout<<s<<"\n";
    cin.get();
    //s.push_back('#');
    int i;
//    for(i=0;i<s.size();i++)
//    {
//        Sir.push_back(s[i]);
//        Letters[s[i]]=i;
//    }
 //   Sir.push_back('#');
    cntGolems=N;
    for(i=1;i<=Q;i++)
    {
        char x,y;
        cin>>x>>y;
        cin.get();
        //cout<<x<<" "<<y<<"\n";
        t.push_back(x);
        d.push_back(y);
    }
    int rez=0,st2,dr1;
    dr1=cautare(0,N-1,1);
    st2=cautare(0,N-1,2);
    if(st2-dr1+1>rez)
    {
        rez=st2-dr1-1;
    }
    cout<<rez;
    return 0;
}
