    #include<cstdio>
    #include<iostream>
    #include <string>
    #include<algorithm>
    using namespace std;

    int main()
    {
        int a[10] = {};
        
        for(int i=0;i<5;i++)
        {
            cin >> a[i];
        }
        int b, num=0;
        cin >> b;
        
        for(int k=0;k<5;k++)
        {
            for(int j=0;j<5;j++)
            {
                if(a[k] > a[j])
                {
                    if(a[k] - a[j] <= b)
                    {
                        num++;
                    }
                    else
                    {
                        num = 0;
                    }
                }
                else if(a[j] > a[k])
                {
                    if(a[j] - a[k] <= b)
                    {
                        num++;
                    }
                    else
                    {
                        num = 0;
                    }
                }
                else
                {
                    if(b>=0)
                    {
                        num++;
                    }
                    else
                    {
                        num =0;
                    }
                }
            }
        }
        if(num == 25)
        {
            cout << "Yay!";
        }
        else
        {
            cout << ":(";
        }
    }
