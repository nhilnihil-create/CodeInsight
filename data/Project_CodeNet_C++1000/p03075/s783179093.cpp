#include<iostream>

using namespace std;

int main(){
    int a[5];
    int k;
    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    bool ans = true;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(abs(a[i]-a[j])>k)
            {
                ans = false;
                break;
            }
        }
    }
    if(ans)
    {
        cout << "Yay!" << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
    return 0;
}