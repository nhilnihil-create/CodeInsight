#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int odd= 0, eve = 0;
    if(a%2)
        odd++;
    else
        eve++;
    if(b%2)
        odd++;
    else
        eve++;
    if(c%2)
        odd++;
    else
        eve++;
    //vector<int>v;
    if(a%2==0 && b%2==0 && c%2==0)
    {
        int cnt = 0;
        while(1)
        {
            if(a==b && b==c)
                break;
            vector<int>v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            sort(v.begin(),v.end());
            a = v[0]+2;
            b = v[1];
            c = v[2];
            cnt++;
        }
        cout << cnt << endl;

    }
    else if(a%2!=0 && b%2!=0 && c%2!=0)
    {
        int cnt = 0;
        while(1)
        {
            if(a==b && b==c)
                break;
            vector<int>v;
            v.push_back(a);
            v.push_back(b);
            v.push_back(c);
            sort(v.begin(),v.end());
            a = v[0]+2;
            b = v[1];
            c = v[2];
            cnt++;
        }
        cout << cnt << endl;

    }
    else
    {
        if(odd<eve)
        {
            int cnt = 1;
            if(a%2)
                b++,c++;
            else if(b%2)
                a++,c++;
            else if(c%2)
                a++,b++;
            while(1)
            {
                if(a==b && b==c)
                    break;
                vector<int>v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                sort(v.begin(),v.end());
                a = v[0]+2;
                b = v[1];
                c = v[2];
                cnt++;
            }
            cout << cnt << endl;



        }

        else
        {
            int cnt = 1;
            if(a%2==0)
                b++,c++;
            else if(b%2==0)
                a++,c++;
            else if(c%2==0)
                b++,a++;
            while(1)
            {
                if(a==b && b==c)
                    break;
                vector<int>v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);
                sort(v.begin(),v.end());
                a = v[0]+2;
                b = v[1];
                c = v[2];
                cnt++;
            }
            cout << cnt << endl;



        }

    }

}
