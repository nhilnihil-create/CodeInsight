#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class __ufnode
{
public:
    __ufnode *m_parent;
    int m_count;

    __ufnode()
    {
        m_parent = this;
        m_count = 1;
    }

    __ufnode *root()
    {
        return _getroot(this);
    }

    bool connect_to(__ufnode *t)
    {
        __ufnode *root = _getroot(this);
        __ufnode *target = _getroot(t);
        if( root == target ) return false;
        if( root->m_count > target->m_count )
        {
            target->m_parent = root;
            root->m_count += target->m_count;
        }
        else
        {
            root->m_parent = target;
            target->m_count += root->m_count;
        }
        return true;        
    }

private:
    __ufnode *_getroot(__ufnode *current)
    {
        if( current->m_parent == current ) return current;
        __ufnode *root = _getroot(current->m_parent);
        current->m_parent = root;
        return root;
    }
};

class unionfind
{
private:
    __ufnode *m_nodes;
    int m_size;

public:
    unionfind(int size)
    {
        m_nodes = new __ufnode[size];
        m_size = size;
    }

    ~unionfind()
    {
        delete m_nodes;
    }

    bool unite(int a, int b)
    {
        return m_nodes[a].connect_to(m_nodes + b);
    }
    
    bool issame(int a, int b)
    {
        return m_nodes[a].root() == m_nodes[b].root();
    }

    // すべてを連結。連結前に何個のグループにわけたか
    int connectall()
    {
        int count = 1;
        for( int i = 1; i < m_size; i++ )
        {
            if( unite(0, i) ) count++;
        }
        return count;
    }
};

int* mallocint(int si)
{
    return (int*) malloc(si * sizeof(int));
}

int* inputint_0(int n)
{
    int *ans = mallocint(n);
    for( int i = 0; i < n; i++ ) 
    {
        cin >> ans[i];
        ans[i]--;
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *p = inputint_0(n);
    unionfind uf(n);
    for( int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x, y);
    }

    int *invp = new int[n];
    for( int i = 0; i < n; i++ ) invp[p[i]] = i;

    int ans = 0;
    for( int i = 0; i < n; i++)
    {
        if( uf.issame(i, invp[i]) ) ans++;
    }

    cout << ans;
}
