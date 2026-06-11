#include<iostream>

using namespace std;

int main(){
    int a[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    int ind = 0;
    for (int i = 0; i < 5; i++)
    {
        if((a[ind]-1)%10>(a[i]-1)%10)
        {
            ind = i;
        }
    }
    int time = 0;
    for (int i = 0; i < 5; i++)
    {
        if(i!=ind)
        {
            if(a[i]%10!=0)
            {
                time += a[i] + 10 - a[i] % 10;
            }
            else
            {
                time += a[i];
            }
        }
        else
        {
            time += a[i];
        }
    }
    cout << time << endl;
    return 0;
}