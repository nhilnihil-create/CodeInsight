#include <iostream>
#include <cstdlib>

using namespace std;

char s[200005], t[200005];
int x, y, n, l, c;

void incearcaSus();
void incearcaJos();
void incearcaDreapta();
void incearcaStanga();

int main()
{
    int i;

    cin >> l >> c >> n;
    cin >> x >> y;
    int cx=x, cy=y;
    cin >> s >> t;
    x = cx; y = cy;
    incearcaSus();
    x = cx; y = cy;
    incearcaJos();
    x = cx; y = cy;
    incearcaDreapta();
    x = cx; y = cy;
    incearcaStanga();
    cout << "YES\n";
    return 0;
}

void incearcaSus()
{
    for (int i=0;i<n;i++)
    {
        if (s[i] == 'U')
            x--;
        if (x == 0)
        {
            cout << "NO\n";
            exit(0);
        }
        if (t[i] == 'D' && x < l)
            x++;
    }
}
void incearcaJos()
{
    for (int i=0;i<n;i++)
    {
        if (s[i] == 'D')
            x++;
        if (x == l+1)
        {
            cout << "NO\n";
            exit(0);
        }
        if (t[i] == 'U' && x > 1)
            x--;
    }
}
void incearcaStanga()
{
    for (int i=0;i<n;i++)
    {
        if (s[i] == 'L')
            y--;
        if (y == 0)
        {
            cout << "NO\n";
            exit(0);
        }
        if (t[i] == 'R' && y < c)
            y++;
    }
}
void incearcaDreapta()
{
    for (int i=0;i<n;i++)
    {
        if (s[i] == 'R')
            y++;
        if (y == c+1)
        {
            cout << "NO\n";
            exit(0);
        }
        if (t[i] == 'L' && y > 1)
            y--;
    }
}