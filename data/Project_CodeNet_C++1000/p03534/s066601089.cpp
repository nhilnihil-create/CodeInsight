#include <iostream>
#include <string>
#include <random>

using namespace std;

void a()
{
    string s;
    cin >> s;
    if(s.size() > 9)
    {
        cout << "NO" << endl;
        return;
    }
    string akb = "AKIHABARA";
    string result = "";
    int index = 0;
    for(int i = 0; i < akb.size(); i++)
    {
        if(s[index] == akb[i] && index < s.size())
        {
            result += s[index];
            index++;
        } else{
            result += "A";
        }
    }
    if(result == akb){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}

void b()
{
    string s;
    cin >> s;
    int a, b, c;
    a = b = c = 0;
    for(auto e : s)
    {
        if(e == 'a') a++;
        if(e == 'b') b++;
        if(e == 'c') c++;
    }
    if(s.size() == 1)
    {
        cout << "YES" << endl;
        return;
    }
    if(s.size() == 3)
    {
        if(a == 2 || b == 2 || c == 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    /*if(s.size() % 3 == 1)
    {
        if(a == b)
        {
           if(c - a == 1)
           {
               cout << "YES" << endl;
               return;
           }
        } else if(a == c){
            if(b - a == 1)
            {
                cout << "YES" << endl;
                return;
            }
        }else if(b == c)
        {
            if(a - b == 1)
            {
                cout << "YES" << endl;
                return;
            }
        }
    }*/
    int rest = s.size();
    string result = "";
    while(rest > 0)
    {
        if(a > 0)
        {
            a--;
            result += "a";
            rest--;
        }
        if(b > 0)
        {
            b--;
            result += "b";
            rest--;
        }
        if(c > 0){
            c--;
            result += "c";
            rest--;
        }
        if(result == "abc")
        {
            result = "";
        }
    }
    /*if(result[result.size() - 1] == result[result.size() - 2])
    {
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }*/
    if(result.size() <= 1)
    {
        cout << "YES" << endl;
        return;
    }
    if(result.size() >= 2)
    {
        if(result[result.size() - 1] == result[result.size() - 2])
        {
            cout << "NO" << endl;
            return;
        }
    }
    if(result.size() > 3)
    {
        cout << "NO" << endl;
        return;
    }
    int l = 0;
    int r = result.size() - 1;
    while (r - l >= 1)
    {
        if(result[l] != result[r])
        {
            cout << "YES" << endl;
            return;
        }
        l++;
        r--;
    }
    cout << "NO" << endl;
}

int main() {
    /*random_device rnd;
    int n = rnd() % 10 + 1;
    string temp;
    for(int i = 0; i < n; i++)
    {
        int num = rnd() % 3;
        if(num == 0)
        {
            temp += "a";
        }
        if(num == 1)
        {
            temp += "b";
        }
        if(num == 2)
        {
            temp += "c";
        }

    }
    cout << temp << endl;*/
    b();
    return 0;
}
